import { resolver } from "blitz"
import db from "db"
import * as z from "zod"

const CreateQuestion = z
  .object({
    text: z.string(),
    choices: z.array(z.object({text: z.string()})),
  })
  .nonstrict()

export default resolver.pipe(resolver.zod(CreateQuestion), resolver.authorize(), async (input) => {
  // TODO: in multi-tenant app, you must add validation to ensure correct tenant
  const question = await db.question.create({
    data: {
      ...input,
      choices: {create: input.choices},
    },
  })

  return question
})
