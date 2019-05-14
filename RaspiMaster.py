import smbus
import time

bus = smbus.SMBus(1)

# This is the Particle Photon address we need to talk to
address = 0x05

def writeNumber(value):
    bus.write_i2c_block_data(address,0x01, [0,0,0,0,1])
    return -1

def readNumber():
    number = bus.read_byte(address)
    # number = bus.read_byte_data(address, 1)
    return number
    
writeNumber([0,0,0,0,1])
print ("RPI: Hi Photon, I sent you somthing, reply with 1")
# sleep one second
time.sleep(1)

number = readNumber()
print ("Arduino: Hey RPI, I received a digit ", number)

