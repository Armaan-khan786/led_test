import serial
import time

ser = serial.Serial("COM6", 115200, timeout=1)
time.sleep(5)  # allow full boot

def read_serial():
    timeout = time.time() + 10  # wait max 10 seconds
    buffer = ""

    while time.time() < timeout:
        if ser.in_waiting:
            data = ser.read(ser.in_waiting).decode(errors='ignore')
            buffer += data
            if "[Info]: Running Application" in buffer:
                return buffer
        time.sleep(0.5)

    return buffer  # return whatever collected

def send_command(cmd):
    ser.reset_input_buffer()
    ser.write((cmd + "\n").encode())

    timeout = time.time() + 10
    buffer = ""

    while time.time() < timeout:
        if ser.in_waiting:
            data = ser.read(ser.in_waiting).decode(errors='ignore')
            buffer += data
            if "LED_IS_ON" in buffer or "LED_IS_OFF" in buffer or "ERROR" in buffer:
                return buffer
        time.sleep(0.5)

    return buffer