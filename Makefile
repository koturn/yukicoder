MAKE     := make
DIR_LIST := $(sort $(wildcard */))

.PHONY: all depends test syntax ctags clean cleanobj
all:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir; \
	done

depends:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done

test:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done

syntax:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done

ctags:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done

clean:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done

cleanobj:
	@for dir in $(DIR_LIST); do \
		$(MAKE) -C $$dir $@; \
	done
