### Makefile ###

# Usage
# 
# 

### Variables ###
CXX := clang
CXXFLAGS := -std=c99 -O2 -pipe -Wall -I include
LDFLAGS := -L lib
LDLIBS := -lSDL2main -lSDL2 -lm
BUILDDIR := build
SDLBUILDDIR := $(BUILDDIR)/sdl
dir_guard = @mkdir -p $(@D)

.PHONY: all multi clean

multi:
	$(MAKE) -j8 all

all: setting-up-sdl creating-a-window events-and-input making-a-pixel-buffer

setting-up-sdl: $(SDLBUILDDIR)/setting-up-sdl
creating-a-window: $(SDLBUILDDIR)/creating-a-window
events-and-input: $(SDLBUILDDIR)/events-and-input
making-a-pixel-buffer: $(SDLBUILDDIR)/making-a-pixel-buffer

$(SDLBUILDDIR)/setting-up-sdl: ./demo-sdl/setting-up-sdl/main.c
	$(dir_guard)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(SDLBUILDDIR)/creating-a-window: ./demo-sdl/creating-a-window/main.c
	$(dir_guard)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(SDLBUILDDIR)/events-and-input: ./demo-sdl/events-and-input/main.c
	$(dir_guard)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(SDLBUILDDIR)/making-a-pixel-buffer: ./demo-sdl/making-a-pixel-buffer/main.c
	$(dir_guard)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

clean:
	rm -rf $(BUILDDIR)