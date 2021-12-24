SRCDIR=./src/
TARGETDIR=./bin/
TARGET=SFMLGame
CXXFLAGS=-std=c++17

# Make sure you clean, before building release target
# Object files may be built for debug mode and be used by the main target
release: $(TARGETDIR)$(TARGET)
$(TARGETDIR)$(TARGET): $(TARGETDIR)main.o $(TARGETDIR)common.o $(TARGETDIR)config.o \
			$(TARGETDIR)font.o $(TARGETDIR)circle.o $(TARGETDIR)rectangle.o
	$(CXX) $(CXXFLAGS) $(TARGETDIR)main.o $(TARGETDIR)common.o $(TARGETDIR)config.o \
		$(TARGETDIR)font.o $(TARGETDIR)circle.o $(TARGETDIR)rectangle.o \
		-o $(TARGETDIR)$(TARGET) \
		-lsfml-graphics -lsfml-window -lsfml-system


# Make sure you clean, before building debug target
# This target is useful for debugging purposes
# If you do not clean, some object files may have missing symbols
debug: $(TARGETDIR)$(TARGET)_debug
$(TARGETDIR)$(TARGET)_debug: CXXFLAGS+=-ggdb
$(TARGETDIR)$(TARGET)_debug: $(TARGETDIR)main.o $(TARGETDIR)common.o $(TARGETDIR)config.o \
			$(TARGETDIR)font.o $(TARGETDIR)circle.o $(TARGETDIR)rectangle.o 
	$(CXX) $(CXXFLAGS) $(TARGETDIR)main.o $(TARGETDIR)common.o $(TARGETDIR)config.o \
		$(TARGETDIR)font.o $(TARGETDIR)circle.o $(TARGETDIR)rectangle.o \
		-o $(TARGETDIR)$(TARGET)_debug \
		-lsfml-graphics -lsfml-window -lsfml-system

$(TARGETDIR)main.o: $(SRCDIR)main.cpp $(SRCDIR)config.h
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)main.cpp -o $(TARGETDIR)main.o

$(TARGETDIR)common.o: $(SRCDIR)common.cpp $(SRCDIR)common.h
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)common.cpp -o $(TARGETDIR)common.o

$(TARGETDIR)config.o: $(SRCDIR)config.cpp $(SRCDIR)config.h
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)config.cpp -o $(TARGETDIR)config.o

$(TARGETDIR)font.o: $(SRCDIR)font.cpp $(SRCDIR)font.h
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)font.cpp -o $(TARGETDIR)font.o

$(TARGETDIR)circle.o: $(SRCDIR)circle.cpp $(SRCDIR)circle.h
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)circle.cpp -o $(TARGETDIR)circle.o

$(TARGETDIR)rectangle.o: $(SRCDIR)rectangle.cpp $(SRCDIR)rectangle.h
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)rectangle.cpp -o $(TARGETDIR)rectangle.o

clean:
	-rm -f $(TARGETDIR)$(TARGET)_debug
	-rm -f $(TARGETDIR)$(TARGET)
	-rm -f $(TARGETDIR)main.o
	-rm -f $(TARGETDIR)common.o
	-rm -f $(TARGETDIR)config.o
	-rm -f $(TARGETDIR)font.o
	-rm -f $(TARGETDIR)circle.o
	-rm -f $(TARGETDIR)rectangle.o
