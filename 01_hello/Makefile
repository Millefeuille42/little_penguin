MODNAME=hello
NAME = hello.ko

obj-m += hello.o

KERNELVER ?= $(shell uname -r)
KERNELDIR ?= /lib/modules/$(KERNELVER)/build

PWD = $(shell pwd)

.PHONY: all clean re info load unload log help

$(NAME): 	
	$(MAKE) --no-print-directory -C "$(KERNELDIR)" M="$(PWD)" modules

all: $(NAME) ## Build the kernel module

clean: ## Clean compiled module and leftovers
	$(MAKE) --no-print-directory -C "$(KERNELDIR)" M="$(PWD)" clean

re: clean ## Clean and recompile
	@make --no-print-directory all

info: $(NAME) ## Show module info
	sudo modinfo "$(NAME)";

load: $(NAME) ## Load the kernel module
	@if lsmod | grep -q "^$(MODNAME)"; then \
		echo "Module is already loaded"; \
	else \
		sudo insmod "$(NAME)"; \
	fi

unload: $(NAME) ## Unload the kernel module
	@if lsmod | grep -q "^$(MODNAME)"; then \
		sudo rmmod "$(NAME)"; \
	else \
		echo "Module is not loaded"; \
	fi

log: ## Show kernel logs related to the module
	sudo dmesg

help: ## Display available commands and their descriptions
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)
