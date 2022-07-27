import asyncio
import time

import numpy as np
import pandas as pd

import serial

async def handshake_arduino(arduino, delay):
    await asyncio.sleep(delay)

    arduino.close()
    arduino.open()

async def get_distance(arduino):
    await handshake_arduino(arduino, 1)

    print(arduino.readline().decode().strip())

if __name__ == "__main__":
    while True:
        asyncio.run(get_distance(serial.Serial(port='COM3', baudrate=1200)))
