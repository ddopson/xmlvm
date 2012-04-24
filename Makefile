
.PHONY: build
build: build/.make.xmlvm
build/.make.xmlvm: $(shell find src/xmlvm src/xmlvm2objc)
	@mkdir -p build	
	@ant
	@touch build/.make.xmlvm


