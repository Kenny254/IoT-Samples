import RPi.GPIO as GPIO
import time
import http.client
import json

ledPin = 7
arduinoPin = 3
GPIO.setmode(GPIO.BOARD)
GPIO.setup(ledPin, GPIO.OUT)
GPIO.setup(arduinoPin, GPIO.IN)

while True:
    if GPIO.input(arduinoPin) == GPIO.HIGH:
        print('Switching ON...')
        client = http.client.HTTPSConnection('vencki-iot-sample.firebaseio.com')
        client.request('PUT','/proximityWarning.json', '{"isClose":true}')
        response = client.getresponse()
        print (response.reason)
        GPIO.output(ledPin, GPIO.HIGH)
    else:
        print('Switching OFF...')
        client = http.client.HTTPSConnection('vencki-iot-sample.firebaseio.com')
        client.request('PUT','/proximityWarning.json', '{"isClose":false}')
        response = client.getresponse()
        print (response.reason)
        GPIO.output(ledPin, GPIO.LOW)

    time.sleep(2)

print('quitting...')
GPIO.cleanup()
