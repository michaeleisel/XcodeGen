import Foundation
import ProjectSpec
import SwiftCLI
import Version
import QuartzCore

public class XcodeGenCLI {
    let cli: CLI

    public init(version: Version) {
        let generateCommand = GenerateCommand(version: version)

        cli = CLI(
            name: "xcodegen",
            version: version.description,
            description: "Generates Xcode projects",
            commands: [
                generateCommand,
                DumpCommand(version: version),
            ]
        )
        cli.parser.routeBehavior = .searchWithFallback(generateCommand)
    }

    public func execute(arguments: [String]? = nil) {
        let start = CACurrentMediaTime()
        let status: Int32
        if let arguments = arguments {
            status = cli.go(with: arguments)
        } else {
            status = cli.go()
        }
        let end = CACurrentMediaTime()
        print("time: \(end - start)")
        exit(status)
    }
}
