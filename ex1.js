// Cho dãy số tự nhiên A. Cài đặt chương trình sắp xếp dãy số A 
// từ nhỏ đến lớn và loại bỏ số không phải là số nguyên tố.

const array = [1, 23, 0, 3, 5, 4, 3, 17, 2, 2, 65, 34, 93, 17, 13]

const isPrime = (n) => {
    if (n < 2) return false
    let count = 0
    for (let i = 1; i <= n; i++) {
        if (n % i === 0) count++
    }
    return count > 2 ? false : true
}

const sort = (arr) => {
    const length = arr.length
    for (let i = 0; i < length - 1; i++) {
        let min = arr[i]
        for (let j = i + 1; j < length; j++) {
            if (arr[j] < arr[i]) {
                min = arr[j]
                arr[j] = arr[i]
                arr[i] = min
            }
        }
    }
    return arr
}

const sortHandson = (arr) => {
    const arrPrime = arr.filter((el, index) => {
        return isPrime(el) === true
    })
    return sort(arrPrime)
}

console.log(sortHandson(array))


