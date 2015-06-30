#!/usr/bin/python
###############################################################################
## Main

from ep import EP

def main():
	ep = EP()
	#ep.loadJson("/home/delvin/code/EP/sample.json")
	#ep.getMinval()

	ep.loadDayBar("/data/daily/HHI.201306.201505.daily.csv")
	#ep.displayData()
	ep.displayScatter()

if __name__ == "__main__":
	main()
