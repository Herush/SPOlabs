set -e

APP=$1

if [ ! -f "$APP" ]; then
	echo "Error: binary not found!"
	exit 1
fi

run_test() {
	local input=$1
	local expected=$2
	local test_num=$3
	
	local output=$(echo "$input" | $APP)
	local result=$(echo "$output" | grep -oP 'words count: \K\d+')
	
	if [ "$result" -eq "$expected" ]; then
		echo "Тест $test_num: Успех"
		return 0
	else
		echo "Тест $test_num: Неудача. Ожидалось $expected, получено $result"
		return 1
	fi
}

echo "Запуск тестов..."
run_test "Salam brother, this is a test." 6 1
run_test "   52brother,,pupupu.bim.bam...   " 4 2
run_test "" 0 3

exit 0
