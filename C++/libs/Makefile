build:
	tup

test:
	make build
	./Conversion/test/build/Conversion.test
	./Environment/test/build/Environment.test
	./Log/test/build/Log.test
	./Sink/test/build/Sink.test

clean:
	cd Conversion; make clean; cd ..
	cd Environment; make clean; cd ..
	cd Log; make clean; cd ..
	cd Sink; make clean; cd ..