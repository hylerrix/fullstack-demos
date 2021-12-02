import { resolver } from "blitz"
import db from "db"
import * as z from "zod"

const DeleteChoice = z
  .object({
    id: z.number(),
  })
  .nonstrict()

export default resolver.pipe(resolver.zod(DeleteChoice), resolver.authorize(), async ({ id }) => {
  // TODO: in multi-tenant app, you must add validation to ensure correct tenant
  const choice = await db.choice.deleteMany({ where: { id } })

  return choice
})
