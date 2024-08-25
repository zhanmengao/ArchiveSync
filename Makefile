

all:cli srv


pb:
	cd proto && buf generate
	

cli:pb

srv:pb