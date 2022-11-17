
import serial
import time


def write():
    ser = serial.Serial('COM12', 115200, timeout=1)
    time.sleep(2)
    f = open("D:\Course Stuff\Fall'22\ESE 519\lab\SDK\lab\sequence.txt", "w")
    if ser.is_open:
        # print(ser.readline())
        read = str(ser.readline())
        f.write(read)
        print(read)
        ser.close()
        f.close()


while True:
    ser = serial.Serial('COM12', 115200, timeout=1)
    print('Enter Input(r: record; n: normal replay; s: slow replay):')
    x = input()
    if(x == 'r'):
        # ser = serial.Serial('COM9', 115200, timeout=1)
        time.sleep(2)
        ser.write(b'r')
        print('Recording start')
        ser.close()
        time.sleep(10)
        print('Recording end')
    elif(x =='n'):
        # ser = serial.Serial('COM9', 115200, timeout=1)
        time.sleep(2)
        print("Starting normal data replay")
        ser.write(b'p')
        ser.close()
        write()
        time.sleep(2)
        print("Replay done")
    elif(x =='s'):
        # ser = serial.Serial('COM9', 115200, timeout=1)
        time.sleep(2)
        print("Starting slow replay of data")
        ser.write(b's')
        ser.close()
        write()
        time.sleep(2)
        print("Replay done")
