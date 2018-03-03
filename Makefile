all:
	$(MAKE) -C chapter-2/
	ln -s -f chapter-2/ch2.out ch2.out
	@echo ""

	$(MAKE) -C chapter-3/
	ln -s -f chapter-3/ch3.out ch3.out
	@echo ""
clean:
	rm -f ch2.out ch3.out
	$(MAKE) clean -C chapter-3/
	$(MAKE) clean -C chapter-2/
