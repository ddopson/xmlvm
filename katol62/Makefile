
XMLVM_DIR      = $(CURDIR)/..
XMLVM          = $(CURDIR)/../bin/xmlvm
IOS_SIM        = $(CURDIR)/bin/ios-sim

java_src_files = $(shell find src/java test -name '*.java')

.PHONY: default
default: javac xmlvm

.PHONY: build
build: xcodebuild

.PHONY: javac
javac: build/.make.javac
build/.make.javac: $(java_src_files)
	@mkdir -p build/classes
	javac -d build/classes $(java_src_files)
	@touch build/.make.javac

.PHONY: xmlvm
xmlvm: javac build/.make.xmlvm
build/.make.xmlvm: build/.make.javac
	$(XMLVM) --in=build/classes/ --out=build/gen-objc --target=objc --enable-ref-counting
	@touch build/.make.xmlvm

.PHONY: xcodebuild
xcodebuild: build/.make.xcodebuild
build/.make.xcodebuild: overrides
	cd build/xcode/dist; xcodebuild -parallelizeTargets -sdk iphonesimulator -configuration Debug | tee $(CURDIR)/xcodebuild.log
	@cat $(CURDIR)/xcodebuild.log | ack '(?<= )(error)(?=: )' || true


.PHONY: clean
clean:
	rm -rf build objc/originals

.PHONY: java
java: javac
	java -cp build/classes/ pkg.Main

.PHONY: run
run:
	@echo > stderr.log
	@$(IOS_SIM) launch build/xcode/dist/build/Debug-iphonesimulator/HelloResources.app --stderr stderr.log --family iphone --setenv NSZombieEnabled=YES --setenv NSDebugEnabled=YES &
	@tail -n10000 -f stderr.log
