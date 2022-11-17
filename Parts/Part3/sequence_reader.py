
import serial
import time


def write():
    ser = serial.Serial('COM9', 115200, timeout=1)
    time.sleep(2)
    f = open("D:\Course Stuff\Fall'22\ESE 519\lab\SDK\lab\sequence.txt", "w")
    print('write start')
    if ser.is_open:
        # print(ser.readline())
        read = str(ser.readline())
        f.write(read)
        print(read)
        ser.close()
        f.close()
    print('write end')


while True:
    ser = serial.Serial('COM9', 115200, timeout=1)
    print('Enter Input:')
    x = input()
    if(x == 'r'):
        # ser = serial.Serial('COM9', 115200, timeout=1)
        time.sleep(2)
        ser.write(b'1')
        print('record start')
        ser.close()
        time.sleep(10)
        print('recorded')
    else:
        # ser = serial.Serial('COM9', 115200, timeout=1)
        time.sleep(2)
        print("print start")
        ser.write(b'0')
        ser.close()
        write()
        time.sleep(2)
        print("printed")
