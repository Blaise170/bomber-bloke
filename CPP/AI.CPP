				DirCount=0;
				if (/*BlokeList[i].XPos%PART==0 && BlokeList[i].YPos%PART==0 && */random(3*(PART/SPEED))==0) {
					if (Maze[BlokeList[i].XPos/PART+1][BlokeList[i].YPos/PART]>'a') {
						if (random(2+2*BlokeList[i].LeftKey)==0) {
							BlokeList[i].RightKey=TRUE;
							BlokeList[i].UpKey=BlokeList[i].DownKey=BlokeList[i].LeftKey=FALSE;
						}
						DirCount++;
					}
					if (Maze[BlokeList[i].XPos/PART-1][BlokeList[i].YPos/PART]>'a') {
						if (random(2+2*BlokeList[i].RightKey)==0) {
							BlokeList[i].LeftKey=TRUE;
							BlokeList[i].UpKey=BlokeList[i].DownKey=BlokeList[i].RightKey=FALSE;
						}
						DirCount++;
					}
					if (Maze[BlokeList[i].XPos/PART][BlokeList[i].YPos/PART+1]>'a') {
						if (random(2+2*BlokeList[i].UpKey)==0) {
							BlokeList[i].DownKey=TRUE;
							BlokeList[i].UpKey=BlokeList[i].RightKey=BlokeList[i].LeftKey=FALSE;
						}
						DirCount++;
					}
					if (Maze[BlokeList[i].XPos/PART][BlokeList[i].YPos/PART-1]>'a') {
						if (random(2+2*BlokeList[i].DownKey)==0) {
							BlokeList[i].UpKey=TRUE;
							BlokeList[i].RightKey=BlokeList[i].DownKey=BlokeList[i].LeftKey=FALSE;
						}
						DirCount++;
					}
					if (DirCount>2) DropBomb(i);
