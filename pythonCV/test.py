import cv2 as cv
import numpy as np
import face_recognition


faceCascade = cv.CascadeClassifier("pythonCV/haarcascade_frontalface_default.xml")
# capture a webcam vide
cap = cv.VideoCapture(0)



cap.set(3,640)
cap.set(4,480)

while True:
    #read from webcam
    success, img = cap.read()
    # flip image (only for webcam)
    img = cv.flip(img, 1)
    #comvert to gray
    imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    # get faces in img
    faces = faceCascade.detectMultiScale(imgGray, 1.1, 4)
    #add bounding box arround each face
    for (x,y,w,h) in faces:
        face = cv.rectangle(img, (x,y),(x+w, y+h),(255,0,0),2)
        cv.circle(face, (x + (w // 2),y + ( h // 4)), 3, (0,0,255), -1)
        cv.putText(face, 'beddygud', (x, y-10), cv.FONT_HERSHEY_SIMPLEX, 0.9, (20,20,255), 2)

    cv.imshow("Video", img)
    if cv.waitKey(1) & 0xFF ==ord('q'):
        break

"""
img = cv.imread("pythonCV/road.jpg")

# resize an image, fx\fy is dim scale
img_half = cv.resize(img, (0,0), fx=.5, fy=.25)

cv.imshow("test_Output", img_half)

cv.waitKey(0)
"""