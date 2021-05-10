TARGET = ex2
LIBS = -lglfw3dll -lglew32 -lopengl32 -static-libstdc++
CC=$(CXX)
CXXFLAGS = -Iinclude -MMD -MP
OBJDIR = obj
SRCDIR = src

rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

.PHONY: default all clean

default: $(TARGET)
all: default

$(shell mkdir -p $(OBJDIR))
SOURCES = $(call rwildcard,$(SRCDIR),*.cpp)
OBJECTS = $(addprefix $(OBJDIR)/,$(patsubst $(SRCDIR)/%.cpp, %.o, $(SOURCES)))
HEADERS = $(call rwildcard,$(SRCDIR),*.hpp)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CC) $(CXXFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f $(OBJDIR)/*.o
	-rm -f $(OBJDIR)/*.d
	-rm -f $(TARGET)

run:
	./$(TARGET)