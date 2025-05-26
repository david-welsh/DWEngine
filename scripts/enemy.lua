function update(deltaTime)
	if targetPos.x < (pos.x - 20) then
		vel.vx = (a * -vel.maxV + (1 - a) * vel.vx)
		if math.abs(vel.vx) < 10.0 then vel.vx = 0.0 end
	elseif targetPos.x > (pos.x + 20) then
		vel.vx = (a * vel.maxV + (1 - a) * vel.vx)
		if math.abs(vel.vx) < 10.0 then vel.vx = 0.0 end
	else
		vel.vx = 0
	end
	
	if c.isGrounded and targetPos.y > pos.y then
		vel.vy = vel.vy + 345
	end

	if math.abs(targetPos.x - pos.x) < 20.0 then
		if state["played"]" ~= true" then
			playSound("enemy")
			state["played"] = "true"
		end
	else
		state["played"] = "false"
	end
end
