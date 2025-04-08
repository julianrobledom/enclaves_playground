# ssh

for ((i = 0; i < 8; i++));
do 
#lfcc=/net/home/robledo/lingua-franca/build/install/lf-cli/bin/lfc
lfcc=/Users/julian.robledo/Documents/lingua-franca/build/install/lf-cli/bin/lfc
$lfcc -c src/enclaves_lf_$i.lf

for ((j = 0; j < 10; j++));
do
./bin/enclaves_lf_$i --workers 10
python3 results.py
done

done