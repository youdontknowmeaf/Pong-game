if [ -z "$1" ]; then
	echo "Argument not provided, please enter localhost port to use. If you are unsure, enter this command:"
	echo "bash $0 8080"
	exit 1
fi

echo "Enter this URL in your browser: http://localhost:$1"
echo "Navigate to: Pong.html"

python3 -m http.server $1
