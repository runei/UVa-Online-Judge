import sys

if __name__ == "__main__":
	n = int(sys.stdin.readline())
	for i in range(0, n):
		team_out = sys.stdin.readline()
		judge_out = sys.stdin.readline()

		if team_out.replace(" ", "") != judge_out.replace(" ", ""):
			print("Case {}: Wrong Answer".format(i+1))
		elif team_out.count(" ") != judge_out.count(" "):
			print("Case {}: Output Format Error".format(i+1))
		else:
			print("Case {}: Yes".format(i+1))