#!/usr/bin/python
###############################################################################
## Main

from ep import EP

def main():
	ep = EP()
	ep.loadDayBar("/data/daily/HHI.201306.201505.daily.csv")
	ep.EPFormula(5, 6, 7)
	ep.displayData()

if __name__ == "__main__":
	main()
