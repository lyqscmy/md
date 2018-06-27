package main

import (
	"fmt"
	"time"
)

func main() {
	for {
		now := time.Now()
		fmt.Println(now)
		time.Sleep(100 * time.Millisecond)
	}
}
