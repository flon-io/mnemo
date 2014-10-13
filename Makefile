
NAME=mnemo

default: $(NAME).o

.DEFAULT spec clean:
	$(MAKE) -C tmp/ $@ NAME=$(NAME)

cs: clean spec

.PHONY: spec clean cs

