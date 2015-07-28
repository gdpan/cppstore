#!/usr/bin/python
###############################################################################
'''
This code is used to generate multicharts code of EP with multiple levels.
'''

levelNum 	= 11
close 		= "close"
ep 			= "ep"
levelDiff	= "levelDiff"
isDayOpen	= "isDayOpen"
posPerLevel = "posPerLevel"

def printUpOutLayerCode(level):
	print("if " + close + " >= " + " ep + " + str(level) + " * " \
		+ levelDiff + " then begin ")
	for i in reversed(range(1, level+1)):
		print('    buytocover ("Exit short at L' + str(i) + ' from UpOutRegion")'
				+ " posPerLevel contract total next bar at "
				+ ep + "+" + str(i) + "*" + levelDiff + " limit;")
	print("    buytocover (\"Exit short at EP from UpOutRegion\")"
				+ " posPerLevel contract total next bar at "
				+ ep + " limit;")
	for i in range(1, level+1):
		print("    buy (\"Long at L-" + str(i) + " from UpOutRegion\")"
				+ " posPerLevel contract next bar at "
				+ ep + "-" + str(i) + "*" + levelDiff + " limit;")
	print("end;");

def printLevel_i_Level_i_plus_1(level):
	print("if " + close + ">=" + ep + "+" + str(level) + "*" \
			+ levelDiff + " and close<" + ep + "+" + str(level+1) + "*" + levelDiff \
			+ " then begin ")
	
	levelAboveII1 = levelNum - level - 1
	levelBelowII1 = level - 1
	interval = 'L' + str(level) + 'L' + str(level+1) 

	for i in range(0, levelAboveII1):
		curLevel = levelNum - i
		print('    sellshort ("Short at L' + str(curLevel) + ' from ' + interval\
				 + '") ' + posPerLevel + ' contracts next '\
				 + 'bar at ' + ep  + '+' + str(curLevel) + '*' + levelDiff + ' limit;') 	
		
	print('    if currentcontracts=' + str(level) + ' or ' + isDayOpen + ' then begin' )
	print('        sellshort("Short at L' + str(level+1) + ' from ' + interval \
					+ '") ' + posPerLevel + ' contracts next bar at '\
					+ ep + "+" + str(level+1) + "*" + levelDiff + ' limit; ')
	print('    end;')

	print('    if currentcontracts=' + str(level+1) + ' then ')
	print('        buytocover ("Exit short at L' + str(level) + ' from ' + interval\
			 		+ '") ' + posPerLevel + ' contract total next bar'\
					+ ' at ' + ep + '+' + str(level) + '*' + levelDiff + ' limit;')
	print('    end;')
	

	for i in reversed(range(1, level)):
		print('    buytocover ("Exit short at L' + str(i) + ' from ' + interval + '")'
				+ ' posPerLevel contract total next bar at '
				+ ep + "+" + str(i) + "*" + levelDiff + " limit;")
	if level > 0:
		print('    buytocover ("Exit short at EP from ' + interval + '")'
				+ " posPerLevel contract total next bar at "
				+ ep  + ' limit;')

	for i in range(1, levelNum+1):
		print('    buy ("Long at L-' + str(i) + ' from ' + interval + '")'
				+ " posPerLevel contract next bar at "
				+ ep + "-" + str(i) + "*" + levelDiff + " limit;")

	print('end;')

def printLevel_i_Level_i_minus_1(level):
	levelAboveII1 = level - 1
	levelBelowII1 = levelNum - level - 1
	interval = 'L-' + str(level) + 'L-' + str(level-1) 

	print("if " + close + ">=" + ep + "-" + str(level) + "*" \
			+ levelDiff + " and close<" + ep + "-" + str(level-1) + "*" + levelDiff \
			+ " then begin ")
	

	for i in range(0, levelNum):
		curLevel = levelNum - i
		print('    sellshort ("Short at L' + str(curLevel) + ' from ' + interval\
				 + '") ' + posPerLevel + ' contracts next '\
				 + 'bar at ' + ep  + '+' + str(curLevel) + '*' + levelDiff + ' limit;') 	
		
	if level > 0:
		print('    buytocover ("Exit short at EP from ' + interval + '")'
				+ " posPerLevel contract total next bar at "
				+ ep  + ' limit;')
	

	print('    if currentcontracts=' + str(level) + ' or ' + isDayOpen + ' then begin' )
	print('        sellshort("Short at L' + str(level+1) + ' from ' + interval \
					+ '") ' + posPerLevel + ' contracts next bar at '\
					+ ep + "+" + str(level+1) + "*" + levelDiff + ' limit; ')
	print('    end;')

	print('    if currentcontracts=' + str(level+1) + ' then ')
	print('        buytocover ("Exit short at L' + str(level) + ' from ' + interval\
			 		+ '") ' + posPerLevel + ' contract total next bar'\
					+ ' at ' + ep + '+' + str(level) + '*' + levelDiff + ' limit;')
	print('    end;')
	

	for i in reversed(range(1, level)):
		print('    buytocover ("Exit short at L' + str(i) + ' from ' + interval + '")'
				+ ' posPerLevel contract total next bar at '
				+ ep + "+" + str(i) + "*" + levelDiff + " limit;")

	for i in range(1, levelNum+1):
		print('    buy ("Long at L-' + str(i) + ' from ' + interval + '")'
				+ " posPerLevel contract next bar at "
				+ ep + "-" + str(i) + "*" + levelDiff + " limit;")

	print('end;')

def main():
	printUpOutLayerCode(levelNum)
	for i in reversed(range(0, levelNum)):
		printLevel_i_Level_i_plus_1(i);
	for i in range(1, levelNum+1):
		printLevel_i_Level_i_plus_1(-i);

if __name__ == "__main__":
	main()
