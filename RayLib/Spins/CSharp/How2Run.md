To run:

1. Install dotnet-sdk-8.0 or newer.
2. ``dotnet run``
3. If you want to compile it: 
    - ``dotnet publish -r {your-platform-here} --self-contained true``
    - The release should be somewhere in bin/dotnet-8/{platform}/publish/

Platforms: win-x64, win-x86, linux-x64, linux-arm64, win-arm64, osx-x64, osx-arm64
