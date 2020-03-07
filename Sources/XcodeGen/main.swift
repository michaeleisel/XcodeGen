import Foundation
import ProjectSpec
import XcodeGenCLI
import Version
import QuartzCore

let start = CACurrentMediaTime()

let version = Version("2.14.0")
let cli = XcodeGenCLI(version: version)
cli.execute()

let end = CACurrentMediaTime()

print("time: \(end - start)")
sleep(10)
