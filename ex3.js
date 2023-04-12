// Cho dãy số A. Có bao nhiêu cặp n số không trùng nhau, liệt kê các cặp số đó. Ví dụ: A = 1,2,3. Khi n = 2 thì 
// kết quả có 3 cặp số, danh sách: 1&2, 1&3, 2&3. Khi n = 3 thì kết quả có 1 cặp số là 1,2,3.

const array = [1, 3, 4, 3, 6, 7, 8, 4, 5, 2, 3, 4, 4, 2, 3, 4]
const num = 3

const filArr = (arr) => {
    let newArr = []
    arr.forEach((el) => {
        if (!newArr.includes(el)) newArr.push(el)
    })
    return newArr
}
// console.log(filArr(array))

const giaiThua = (n) => {
    if (n < 0) return new Error("Wrong input number")
    if (n === 0) return 1
    let gt = 1
    for (let i = 1; i <= n; i++) {
        gt *= i
    }
    return gt
}

const result = (arr, k) => {
    const arrFil = filArr(arr)
    // console.log(arrFil)
    const n = arrFil.length
    if (k <= 0 || k > n) return new Error('Wrong number k')
    return giaiThua(n) / (giaiThua(k) * giaiThua(n - k))
    // kCn = n! / (k! * (n-k)!)
}

console.log(result(array, num))


