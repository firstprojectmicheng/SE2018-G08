ͳ����ҷ��� seq
	��Ϸ����
	��ȡ��ǰ��ҷ���
	��ʾ��ǰ��ҷ���
	number:=0
	������ iter until ���а���ʾ
		�������а��������Ϣ iter util �ҵ���ǰ��� 
			�Ƚ����а���Ϣ select ���а��������Ϣ==��ǰ�����Ϣ
				�Ƚ����а����� select ���а�����ҷ���<��ҵ�ǰ����
					���а�����ҷ���=��ҵ�ǰ����
					number:=number+1 
				�Ƚ����а����� end
			�Ƚ����а���Ϣ end	
		�������а��������Ϣ end 
		�ж�number select number==0
			��������Ϣ
			�����ҵ�ǰ���� 
		�ж�number end
		���������㷨
		�ϴ��µ����а���Ϣ
		��ʾ���а���Ϣ 
	������ end	 
ͳ����ҷ��� end 


procedure :score
	list p=���а�; 
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
		p =new ���а� 
		p[i].name=name;
		p[i].score=score;
	end if
	sort();
end
