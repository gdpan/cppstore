#!/usr/bin/python
###############################################################################
## EP class is for backtesting EP parameters

import csv
import matplotlib.pyplot as plt
from bar import DayBar 
import json
from pprint import pprint

class EP:

	def __init__(self):
		self.daybars = []
		self.cls = []
		self.ops = []
		self.smas = []
		self.emas = []
		self.json = []

	def loadDayBar(self, filepath):
		''' Load day bars from a file
		'''
		with open(filepath, 'rb') as csvfile:
			reader = csv.reader(csvfile)
			for row in reader:
				bar = DayBar()
				if bar.parse(row):
					self.daybars.append(bar)
					self.cls.append(bar.cl)
					self.ops.append(bar.op)

	def loadJson(self, filepath):
		try:
			with open(filepath) as f:
				data = json.load(f)
			self.json = data
			
		except Exception as inst:
			print "Load Json failed"
			print inst
	
	def getMinval(self):
		minVal  = self.json[0].val
		print minVal

	def getValSurface(self):
		pass


	def displayData(self):
		plt.plot(self.cls)
		plt.plot(self.ops, "g-")
		#plt.plot(self.smas, "r--")
		#plt.plot(self.emas, "g.")
		plt.xlabel("days")
		plt.ylabel("Price")
		plt.show()

	def displayScatter(self):
		coratio = []
		ocratio = []
		for c in range(0, len(self.cls)-1):
			coratio.append(float(self.ops[c+1] - self.cls[c])/self.cls[c]*100)
			ocratio.append(float(self.cls[c+1] - self.ops[c+1])/self.ops[c+1]*100)

		plt.scatter(coratio, ocratio)
		plt.xlabel("Gap Percent")
		plt.ylabel("Daily Change Percent")
		plt.grid()
		plt.show()	

	def EPFormula(self, SMAPeriod, EMAPeriod, SDPeriod):
		start = max([SMAPeriod, EMAPeriod, SDPeriod])
		self.SMA(start, SMAPeriod)
		self.EMA(start, 2/float(EMAPeriod+1))

	def SMA(self, start, SMAPeriod):
			init = sum(self.cls[start-SMAPeriod:start-1])
			smas = [0] * len(self.cls)
			for id in range(start, len(self.cls)):
				smas[id] = (init + self.ops[id])/SMAPeriod
				init = init - self.cls[id-SMAPeriod] + self.cls[id-1]
			self.smas = smas

	def EMA(self, start, weight): # weight = 2/(N+1)
			emas = [0] * len(self.cls)
			print self.cls
			init = self.cls[0]*(1-weight) + self.cls[1] * weight
			print init

			for id in range(2, start):
				init = init * (1-weight) + self.cls[id] * weight
				print init

			for id in range(start, len(self.cls)):
				emas[id] = init * (1-weight) + self.ops[id] * weight
				init = init * (1-weight) + self.cls[id] * weight
				print "init ", init
				print "ops ", self.ops[id]
				print "cls ", self.cls[id]
				print "emas ", emas[id]

			self.emas = emas

	def SD(self, start, SDPeriod):
			pass	

	def Optimize(self):
		pass


# end of EP
