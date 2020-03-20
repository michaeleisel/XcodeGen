import Foundation
import ProjectSpec
import XcodeGenCLI
import Version
import QuartzCore

let start = CACurrentMediaTime()

print("go")
let version = Version("2.14.0")
let cli = XcodeGenCLI(version: version)
cli.execute()
let end = CACurrentMediaTime()
print("time: \(end - start)")
let a = "asdf"
a.withCString { z in
    write(1, z, 4)
}
