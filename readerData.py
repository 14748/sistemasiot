#!/bin/python3
import serial
import mysql.connector
ser = serial.Serial('/dev/ttyAMA0', 38400)
try:
	while 1:
        # Read one line from the serial buffer
		line = ser.readline()

        # Remove the trailing carriage return line feed
		line = line[:-2].decode("utf-8")

        # Create an array of the data
		Z = line.split(',')
		print ("Voltios:\t%s"%(Z[1]))
		cnx = mysql.connector.connect(user='admin',password='iot',host='127.0.0.1',database='InfoElectrica')
		cursor = cnx.cursor()
		double = float(Z[1])
		print(double)
		from datetime import datetime
		sql = "INSERT INTO datos (voltaje, hostname, fechadatos)  VALUES(%s, %s, %s)"
		data = (Z[1], 'pepito', datetime.now())
		cursor.execute(sql, data)
		cnx.commit()
		cursor.close
		cnx.close()
		print("Pasado a DDBB")
	#print ("Tension:\t%s"%(Z[1]))
        # Print it nicely
        # if len(Z)>15:
        # print ("----------")
        # print ("Vrms:\t%s" % Z[15])
        # print ("          \tCT1\tCT2\tCT3\tCT4\tCT5\tCT6\tCT7")
        # print ("RealPower:\t%s\t%s\t%s\t%s\t%s\t%s\t%s" % (Z[1], Z[2], Z[3], Z[4], Z[5], Z[6], Z[7]))
        # print ("Irms     :\t%s\t%s\t%s\t%s\t%s\t%s\t%s" % (Z[8], Z[9], Z[10], Z[11], Z[12], Z[13], z[14]))


except KeyboardInterrupt:
    ser.close()
