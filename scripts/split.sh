total_size=$(stat --format=%s file)
block_size=$(($total_size / 100))
split -b $block_size --numeric-suffixes=1 --suffix-length=3 file prefix_