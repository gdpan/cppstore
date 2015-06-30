#!/usr/bin/python
###############################################################################
## Bar class

class DayBar:

	def __init__(self):
		self.dt = ''
		self.op = 0
		self.hi = 0
		self.lo = 0
		self.cl = 0
		self.vol = 0

	def init(self, date, op, hi, lo, cl, vol):
		self.dt = date
		self.op = op
		self.hi = hi
		self.lo = lo
		self.cl = cl
		self.vol = vol

	def parse(self, record):
		try:
			dt, op, cl, hi, lo, vol = record
			self.init(dt, float(op), float(hi), float(lo),
						float(cl), float(vol))
			return True
		except Exception as inst:
			print "Cannot create bar from record ", record
			print "Reason: ", inst
			print "Just ignore it"
			return False

	def display(self):
		print 	"Bar date ", self.dt,\
				" open ", self.op,\
			  	" high ", self.hi, \
				" low ", self.lo, \
				" close ", self.cl	
