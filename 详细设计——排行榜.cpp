统计玩家分数 seq
	游戏结束
	读取当前玩家分数
	显示当前玩家分数
	number:=0
	程序体 iter until 排行榜显示
		查找排行榜中玩家信息 iter util 找到当前玩家 
			比较排行榜信息 select 排行榜中玩家信息==当前玩家信息
				比较排行榜数据 select 排行榜中玩家分数<玩家当前分数
					排行榜中玩家分数=玩家当前分数
					number:=number+1 
				比较排行榜数据 end
			比较排行榜信息 end	
		查找排行榜中玩家信息 end 
		判断number select number==0
			添加玩家信息
			添加玩家当前分数 
		判断number end
		调用排序算法
		上传新的排行榜信息
		显示排行榜信息 
	程序体 end	 
统计玩家分数 end 


procedure :score
	list p=排行榜; 
	int number=0;
	loop util i<p.length
		if p[i].name==name
			if p[i].score<score
				p[i].score=score
			end if
			number=1;
		end if
	end loop
	if number==1
		p =new 排行榜； 
		p[i].name=name;
		p[i].score=score;
	end if
	sort();
end
