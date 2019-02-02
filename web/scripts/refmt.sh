reason_files=$(find ./src -name "*.re")
for f in $reason_files
do
  refmt --in-place "$f"
done