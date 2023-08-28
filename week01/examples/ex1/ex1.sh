echo > namelist
echo "name1" > namelist
echo "name2" >> namelist
echo "4ier" >> namelist
echo "12ier" >> namelist
echo "44er" >> namelist

echo "namelist content:"
cat namelist

# sort -r namelist

sort -r -n < namelist > namelist.sorted

printf "\nnamelist.sorted content:\n"
cat namelist.sorted
