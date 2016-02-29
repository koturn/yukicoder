MAKE     := make
DIR_LIST := $(sort $(wildcard */))


.PHONY: all
all:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir; \
	done

.PHONY: test
test:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done

.PHONY: clean
clean:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done

.PHONY: cleanobj
cleanobj:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done
