import Foundation

func solution(_ absolutes:[Int], _ signs:[Bool]) -> Int {
    
    let signsToNum = signs.map { $0 ? 1 : -1 }
    return zip(absolutes, signsToNum).map { $0 * $1 }.reduce(0, +)   
}