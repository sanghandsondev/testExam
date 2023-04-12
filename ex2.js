// Cài đặt chương trình tìm số thứ N trong dãy Fibonacci.

// const fibonacci = (n) => {
//     if (n === 1 || n === 2)
//         return 1
//     return fibonacci(n - 1) + fibonacci(n - 2)
// }
// console.log(fibonacci(100))

const fibonacci2 = (n) => {
    if (n < 0) return new Error("Wrong input number")
    let [num1, num2] = [1, 1]
    let num3
    if (n === 1 || n === 2)
        return 1
    for (let i = 3; i <= n; i++) {
        num3 = num1 + num2
        num1 = num2
        num2 = num3
    }
    return num3
}
console.log(fibonacci2(100))