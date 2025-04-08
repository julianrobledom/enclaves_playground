import csv
import os
import glob

path = '.'
extension = 'csv'
os.chdir(path)
csv_files = glob.glob('*.{}'.format(extension))
print(csv_files)
missed_deadlines = list()
processed_users = list()
end_time = list()

for file in csv_files:
    if file.startswith('output'):
        with open(file, newline='') as csvfile:
            spamreader = csv.reader(csvfile, delimiter=',')
            for row in spamreader:
                missed_deadlines.append(int(row[0]))
                processed_users.append(int(row[1]))
                end_time.append(int(row[2]))
        os.remove(file)

    if file.startswith('trace_manager'):
        with open(file, newline='') as csvfile:
            spamreader = csv.reader(csvfile, delimiter=',')
            for row in spamreader:
                print(row, "row")
                #prbs = row[0]
                #lays = row[1]
                num_users = int(row[0])
                init_time = int(row[1])
                version = row[2]
                #enable_deadline = int(row[5])
        os.remove(file)

with open("results.csv", 'a', newline='') as csvfile:
    execTime = max(end_time) - init_time
    #print(enable_deadline)
    missed_deadlines = sum(missed_deadlines)
    processed_users = sum(processed_users)
    #print(missed_deadlines)

    #if enable_deadline == False:
    print("total processed users: ", num_users - missed_deadlines)
    print("total missed deadlines: ", missed_deadlines)
    #else:
    #    missed_deadlines = num_users - processed_users
    #    print("total processed users: ", processed_users)
    #    print("total missed deadlines: ", missed_deadlines)
    
    spamwriter = csv.writer(csvfile, delimiter=',')
    #spamwriter.writerow(['prbs','layers','users','execTime',
    #                     'version','missed_deadlines','deadline'])
    spamwriter.writerow([#prbs,
                         #lays,
                         num_users,
                         execTime,
                         version,
                         missed_deadlines,
                         #enable_deadline
                         ])


