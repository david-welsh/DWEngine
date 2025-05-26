function update(deltaTime)
    if c.isGrounded and targetPos.y > pos.y then
        vel.vy = vel.vy + 700
    end
end
