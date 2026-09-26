#!/bin/bash

cd "$(dirname "$0")/.."

FAIL=0
UTILS="test/test_utils.c"

for test_src in test/test_*.c; do
	name=$(basename "$test_src" .c)
	if [ "$name" = "test_utils" ]; then
		continue
	fi
	cc -Wall -Wextra -Werror -Iinc -Itest "$UTILS" "$test_src" \
		-L. -lft -o "test/$name"
	if [ $? -ne 0 ]; then
		printf "\033[31mCOMPILE FAIL: %s\033[0m\n" "$name"
		FAIL=$((FAIL + 1))
		continue
	fi
	./"test/$name"
	ret=$?
	if [ $ret -ne 0 ]; then
		FAIL=$((FAIL + ret))
	fi
done

rm -f test/test_is test/test_mem test/test_mem2 test/test_str
rm -f test/test_str2 test/test_str3 test/test_str4 test/test_conv
rm -f test/test_put test/test_lst1 test/test_lst2 test/test_lst3

echo ""
if [ $FAIL -eq 0 ]; then
	printf "\033[1;32m  ALL TESTS PASSED!\033[0m\n"
else
	printf "\033[1;31m  SOME TESTS FAILED!\033[0m\n"
fi
echo ""
exit $FAIL
