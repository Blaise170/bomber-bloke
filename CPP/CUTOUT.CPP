
					// if two escape routes, which is quickest off this square?
					if (BlokeList[i].LeftKey && BlokeList[i].RightKey) {
						BlokeList[i].LeftKey=FALSE;
						BlokeList[i].RightKey=FALSE;
						// which square is dangerous?
						if (AIMaze[CurX/PART][CurY/PART]=='x') {
						 if (CurX%PART==0) BlokeList[i].LeftKey=!(BlokeList[i].RightKey=random(2)); else
							 BlokeList[i].RightKey=TRUE;
						}
						if (AIMaze[CurX/PART+(CurX%PART!=0)][CurY/PART]=='x') {
							 BlokeList[i].LeftKey=TRUE;
						}
					}
					if (BlokeList[i].UpKey && BlokeList[i].DownKey) {
						BlokeList[i].UpKey=FALSE;
						BlokeList[i].DownKey=FALSE;
						// which square is dangerous?
						if (AIMaze[CurX/PART][CurY/PART]=='x') {
						 if (CurY%PART==0) BlokeList[i].UpKey=!(BlokeList[i].DownKey=random(2)); else
							 BlokeList[i].DownKey=TRUE;
						}
						if (AIMaze[CurX/PART][CurY/PART+(CurY%PART!=0)]=='x') {
							 BlokeList[i].UpKey=TRUE;
						}
					}
