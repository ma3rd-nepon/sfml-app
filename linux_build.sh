cmake --build build -j$(nproc)
cp -r ./src/assets ./build/bin/assets
if [ ! -d "./build/bin/assets" ]; then
  echo "copy assets failed"
fi