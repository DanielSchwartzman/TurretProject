import pathlib
import serial
import time
import cv2
import math

arduino = serial.Serial('COM5', 9600)

cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

cascade_path = pathlib.Path(cv2.__file__).parent.absolute() / "data/haarcascade_frontalface_default.xml"
clf = cv2.CascadeClassifier(str(cascade_path))


def distance(x_coordinate, y_coordinate):
    return math.sqrt(((x_coordinate - 240) ** 2) + ((y_coordinate - 320) ** 2))


while True:
    ret, frame = cap.read()

    if ret:
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        faces = clf.detectMultiScale(
            gray,
            scaleFactor=1.1,
            minNeighbors=5,
            minSize=(30, 30),
            flags=cv2.CASCADE_SCALE_IMAGE
        )

        # Find the closest face to the camera
        dist = 1000
        closest_x = 640
        closest_y = 480
        for(x, y, width, height) in faces:
            current_distance = distance(x+width/2, y+height/2)
            if dist > current_distance:
                dist = current_distance
                closest_x = x+width/2
                closest_y = y+height/2

        x_on_target = False
        y_on_target = False

        # Check if the closest face X coordinate is at the middle of the screen
        if closest_x > 330:
            x_on_target = False
            i = '1'
            arduino.write(i.encode())
        elif closest_x < 310:
            x_on_target = False
            i = '2'
            arduino.write(i.encode())
        else:
            x_on_target = True

        # Check if the closest face Y coordinate is at the middle of the screen
        if closest_y > 250:
            y_on_target = False
            i = '3'
            arduino.write(i.encode())
        elif closest_y < 230:
            y_on_target = False
            i = '4'
            arduino.write(i.encode())
        else:
            y_on_target = True

        # Check if current camera position is aiming exactly at a persons face
        if x_on_target & y_on_target:
            i = '0'
            arduino.write(i.encode())

        cv2.imshow('video', frame)
        time.sleep(0.1)

    key = cv2.waitKey(1)
    if key == ord('q'):
        break

cv2.destroyAllWindows()
