// swift-tools-version:5.0

import PackageDescription

let package = Package(
    name: "XcodeGen",
    platforms: [.macOS(.v10_13)],
    products: [
        .executable(name: "xcodegen", targets: ["XcodeGen"]),
        .library(name: "XcodeGenKit", targets: ["XcodeGenKit"]),
        .library(name: "ProjectSpec", targets: ["ProjectSpec"]),
    ],
    dependencies: [
        .package(url: "https://github.com/jpsim/Yams.git", from: "2.0.0"),
        .package(url: "https://github.com/yonaskolb/JSONUtilities.git", from: "4.2.0"),
        .package(url: "https://github.com/kylef/Spectre.git", from: "0.9.0"),
        .package(url: "https://github.com/onevcat/Rainbow.git", from: "3.0.0"),
        .package(url: "https://github.com/tuist/XcodeProj.git", .exact("7.8.0")),
        .package(url: "https://github.com/jakeheis/SwiftCLI.git", from: "6.0.0"),
        .package(url: "https://github.com/mxcl/Version", from: "2.0.0"),
    ],
    targets: [
        .target(name: "XcodeGen", dependencies: [
            "XcodeGenCLI",
            "Version",
        ]),
        .target(name: "XcodeGenCLI", dependencies: [
            "XcodeGenKit",
            "ProjectSpec",
            "SwiftCLI",
            "Rainbow",
            "Version",
        ]),
        .target(name: "XcodeGenKit", dependencies: [
            "ProjectSpec",
            "JSONUtilities",
            "XcodeProj",
            "Core",
        ]),
        .target(name: "ProjectSpec", dependencies: [
            "JSONUtilities",
            "XcodeProj",
            "Yams",
            "Core",
            "Version",
        ]),
        .target(name: "Core", dependencies: [
            "Yams",
        ]),
        .target(name: "TestSupport", dependencies: [
            "XcodeProj",
            "Spectre",
        ]),
        .testTarget(name: "XcodeGenKitTests", dependencies: [
            "XcodeGenKit",
            "Spectre",
            "TestSupport",
        ]),
        .testTarget(name: "FixtureTests", dependencies: [
            "XcodeGenKit",
            "Spectre",
            "TestSupport",
        ]),
        .testTarget(name: "CoreTests", dependencies: [
            "Core",
            "Spectre",
            "TestSupport",
        ]),
        .testTarget(name: "ProjectSpecTests", dependencies: [
            "ProjectSpec",
            "Spectre",
            "TestSupport",
        ]),
        .testTarget(name: "PerformanceTests", dependencies: [
            "XcodeGenKit",
            "Spectre",
            "TestSupport",
        ]),
    ]
)
