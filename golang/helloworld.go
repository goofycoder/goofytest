/*
 *   first go code
 */
package main

import "fmt"

// first function   
// note the order of return type
// note the type is after the var name
func add(x int, y int) int {
    return x+y
}

// named results of function return values
func split(sum int) (x,y int) {
    x = sum*2/3

    y = sum-x

    return
}

func main() {
    fmt.Println("Hello world!")

    var sum int         // declare variable
    
    sum = add(12,7)

    fmt.Println(sum)

    var x,y int
    x,y = split(23)
    
    fmt.Println(x,y)
}
